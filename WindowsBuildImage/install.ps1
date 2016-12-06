wget http://go.microsoft.com/fwlink/?LinkId=691126 -OutFile buildtools.exe -UseBasicParsing
./buildtools.exe
$env:chocolateyUseWindowsCompression = 'false'
iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
choco install nodejs  -y
