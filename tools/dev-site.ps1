$ErrorActionPreference = "Stop"

$root = Resolve-Path (Join-Path $PSScriptRoot "..")
$watchScript = Join-Path $PSScriptRoot "watch-site.ps1"
$port = 8765

$watchJob = Start-Job -ScriptBlock {
  param($scriptPath)
  powershell -ExecutionPolicy Bypass -File $scriptPath
} -ArgumentList $watchScript

Write-Host "Dashboard watcher started."
Write-Host "Serving http://localhost:$port"
Write-Host "Press Ctrl+C to stop the server and watcher."

try {
  Set-Location $root
  python -m http.server $port
}
finally {
  Stop-Job $watchJob -ErrorAction SilentlyContinue
  Remove-Job $watchJob -Force -ErrorAction SilentlyContinue
}
