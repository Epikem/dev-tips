# Clear-Content .\snippets.cson
# Add-Content .\snippets.cson -Encoding "UTF8" -Value (Get-Content -Path ".\snippets\*.cson" -Encoding "UTF8")

Clear-Content .\snippets.cson
$FileList = (Get-ChildItem '.\source' |? { ! $_.PSIsContainer -and $_.FullName -notmatch 'how to' -and $_.FullName -match '.cson'}).FullName
echo $FileList
$FileList |? {Add-Content .\snippets.cson -Encoding "UTF8" -Value ( Get-Content -Path $_ -Encoding "UTF8")}

cat .\snippets.cson > C:\Users\Administrator\.atom\snippets.cson
