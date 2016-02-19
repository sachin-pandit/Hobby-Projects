

i=1
while [ $i -lt 100 ] 
do
	echo "Iteration $i"
	if [ -f temp.txt ]
	then 
		rm reg_temp.txt
	fi
	
	if [ -f dump.txt ]
	then 
		rm dump.txt
	fi
	curl 'http://localhost/xampp/php/register.php' > reg_temp.txt
	hash=`./a.out pass$i`
	pub=`awk "NR==164" reg_temp.txt`
	y=`echo $pub^$hash%10000000000 | bc`
	curl -d username="user$i" -d hashValue="$y" -d age="$i" -d college="SJCE" 'http://localhost/xampp/php/register_save.php' >> dump.txt
	i=$[$i+1]
	sleep .1;
	echo " ";
	echo " ";
	echo " ";
	echo " ";

done
