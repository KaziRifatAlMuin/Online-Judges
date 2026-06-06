$ErrorActionPreference = "Stop"

$root = Resolve-Path (Join-Path $PSScriptRoot "..")
$outputPath = Join-Path $root "site-data.js"

$codeExtensions = @{
  ".c" = "c"
  ".cc" = "cpp"
  ".cpp" = "cpp"
  ".cxx" = "cpp"
  ".h" = "cpp"
  ".hpp" = "cpp"
  ".java" = "java"
  ".py" = "python"
  ".js" = "javascript"
  ".ts" = "typescript"
  ".cs" = "csharp"
  ".go" = "go"
  ".rs" = "rust"
  ".kt" = "kotlin"
  ".php" = "php"
  ".rb" = "ruby"
  ".swift" = "swift"
  ".md" = "markdown"
}

$skipDirectories = @(
  ".git",
  "node_modules",
  ".next",
  "dist",
  "build",
  "coverage"
)

$skipFiles = @(
  "index.html",
  "site-data.js",
  "package.json"
)

function Get-RelativePath([string]$basePath, [string]$targetPath) {
  $baseUri = [System.Uri]::new(($basePath.TrimEnd("\") + "\"))
  $targetUri = [System.Uri]::new($targetPath)
  return [System.Uri]::UnescapeDataString($baseUri.MakeRelativeUri($targetUri).ToString()).Replace("/", "\")
}

function Test-IsSkipped([System.IO.FileInfo]$file) {
  if ($skipFiles -contains $file.Name) {
    return $true
  }

  $relative = Get-RelativePath $root.Path $file.FullName
  $parts = $relative -split "\\"
  foreach ($part in $parts) {
    if ($skipDirectories -contains $part) {
      return $true
    }
  }

  return $false
}

$files = @(Get-ChildItem -Path $root -Recurse -File -Force |
  Where-Object {
    -not (Test-IsSkipped $_) -and $codeExtensions.ContainsKey($_.Extension.ToLowerInvariant())
  } |
  Sort-Object FullName)

$items = foreach ($file in $files) {
  $relativePath = Get-RelativePath $root.Path $file.FullName
  $extension = $file.Extension.ToLowerInvariant()
  $folderParts = ($relativePath -split "\\")
  $topFolder = if ($folderParts.Count -gt 1) { $folderParts[0] } else { "Root" }

  [pscustomobject]@{
    name = $file.Name
    path = $relativePath.Replace("\", "/")
    folder = $topFolder
    directory = if ($folderParts.Count -gt 1) { ($folderParts[0..($folderParts.Count - 2)] -join "/") } else { "Root" }
    extension = $extension.TrimStart(".")
    language = $codeExtensions[$extension]
    size = $file.Length
    lines = 0
    modified = $file.LastWriteTime.ToString("o")
  }
}

$generatedAt = (Get-Date).ToString("o")
$totalLines = ($items | Measure-Object -Property lines -Sum).Sum
$totalSize = ($items | Measure-Object -Property size -Sum).Sum

$data = [pscustomobject]@{
  generatedAt = $generatedAt
  rootName = Split-Path $root -Leaf
  totalFiles = @($items).Count
  totalLines = if ($null -eq $totalLines) { 0 } else { $totalLines }
  totalSize = if ($null -eq $totalSize) { 0 } else { $totalSize }
  files = @($items)
}

$json = $data | ConvertTo-Json -Depth 8 -Compress
$payload = "window.REPO_DATA = $json;"
Set-Content -LiteralPath $outputPath -Value $payload -Encoding UTF8
Write-Host "Updated site-data.js with $(@($items).Count) files."
