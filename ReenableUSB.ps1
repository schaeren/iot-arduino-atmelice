#Requires -RunAsAdministrator

$global:InstanceId = Get-PnpDevice | Where-Object {$_.FriendlyName -eq 'Unknown USB Device (Device Descriptor Request Failed)' -and $_.Status -eq 'Error'} | Select-Object -ExpandProperty InstanceId
Write-Host $InstanceId
if ($global:InstanceId -eq '') {
    Write-Host "No 'Unknown USB Device (Device Descriptor Request Failed)' found."
    Exit
}
Write-Host `Disabling USB device with ID $global:InstanceId`
Disable-PnpDevice -InstanceId $global:InstanceId -Confirm:$false

Start-Sleep -Seconds 1

Write-Host `Enabling USB device with ID $global:InstanceId`
Enable-PnpDevice -instanceId $global:InstanceId -Confirm:$false
