r:
	pwsh -command "Get-Content .\input.txt | python .\main.py"
ppt:
	pwsh -command "Get-Content .\input.txt | pypy3 .\main.py" test
t:
	pwsh -command "Get-Content .\input.txt | python .\main.py" test
rc:
	py-backwards -i .\main.py -o .\compiled.py -t 3.4
	pwsh -command "Get-Content .\input.txt | python .\compiled.py"
tc:
	py-backwards -i .\main.py -o .\compiled.py -t 3.4
	pwsh -command "Get-Content .\input.txt | python .\compiled.py" test
p:
	pwsh -command "Get-Content .\input.txt | python .\bojLogProcessor.py" test
lr:
	cat ./input.txt | python3 ./main.py

