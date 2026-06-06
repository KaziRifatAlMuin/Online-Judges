$ErrorActionPreference = "Stop"

$root = Resolve-Path (Join-Path $PSScriptRoot "..")
$updateScript = Join-Path $PSScriptRoot "update-site-data.ps1"

& $updateScript

$watcher = [System.IO.FileSystemWatcher]::new($root.Path)
$watcher.IncludeSubdirectories = $true
$watcher.EnableRaisingEvents = $true
$watcher.NotifyFilter = [System.IO.NotifyFilters]'FileName, DirectoryName, LastWrite, Size'

$pending = $false
$lastRun = Get-Date

$action = {
  $path = $Event.SourceEventArgs.FullPath
  if ($path -match "\\.git\\|\\node_modules\\|\\site-data\.js$|\\index\.html$") {
    return
  }

  $script:pending = $true
}

$subscriptions = @(
  Register-ObjectEvent $watcher Changed -Action $action
  Register-ObjectEvent $watcher Created -Action $action
  Register-ObjectEvent $watcher Deleted -Action $action
  Register-ObjectEvent $watcher Renamed -Action $action
)

Write-Host "Watching repository for updates. Press Ctrl+C to stop."

try {
  while ($true) {
    Start-Sleep -Milliseconds 500
    if ($pending -and ((Get-Date) - $lastRun).TotalSeconds -ge 1) {
      $pending = $false
      $lastRun = Get-Date
      & $updateScript
    }
  }
}
finally {
  foreach ($subscription in $subscriptions) {
    Unregister-Event -SubscriptionId $subscription.Id -ErrorAction SilentlyContinue
  }
  $watcher.Dispose()
}
