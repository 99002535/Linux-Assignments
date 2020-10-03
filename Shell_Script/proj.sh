
#!/bin/bash
#Suraj
input=Input.csv
OLDIFS=$IFS
IFS=','
[ ! -f $input ] && { echo "$INPUT file not found"; exit 99; }
sed 1d $input | while read -r Name email repolink
do
	echo "Name : $Name"
	echo "Email ID : $email"
	echo "Repo Link : $repolink"
      	git clone $repolink
      	folder=$(echo -e $repolink |awk '/L.-/')
	echo "The folder to go into is $folder "
done < $input
IFS=$OLDIFS

