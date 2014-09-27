i='y';
while [ "$i" = 'y' ]
do
	clear;
	echo "Enter user name : "
	read number_user;
	echo "Enter password : "
	read number_pass;
	i=1;

	if [ -f log_temp ]
	then
		rm log_temp
	fi

	#echo "login"
	curl http://localhost/xampp/php/login.php > log_temp

	a=`awk "NR==160" log_temp`

	if [ -f temp ]
	then
		rm temp
	fi

	#echo "Register"
	curl http://localhost/xampp/php/register.php > temp

	pub=`awk "NR==164" temp`
	hash=`./a.out $number_pass`

	y=`echo $pub^$hash%10000000000 | bc`

	if [ $hash -lt 5 ]
	then 
		rand="$RANDOM"
		rand=`echo $rand%10 | bc`
		rand=`echo $rand+60 | bc`
	else
		rand="$RANDOM"
		rand=`echo $rand%10 | bc`
		rand=`echo $rand+135 | bc`
	fi	


	c=`echo "($y+ $pub^$rand +$a)%15" | bc`



	#echo -e " Script output"
	#echo -e "c = $c"

	#echo -e "a = $a"
	#echo -e "pub = $pub"


	z=`echo $rand-$c*$hash | bc`
	#echo "z = $z"

	#echo -e " PHP output"

	message=`curl -d username="$number_user" -d cvalue="$c" -d zvalue="$z" -d submit="Submit" http://localhost/xampp/php/login_verify.php`
	
	message=`echo $message | grep "LOGIN SUCCESSFUL" | wc -c`
	
	if [ $message = 0 ]
	then
		echo " ";
		echo "Login failed";
		echo "Do you want to try again( press 'Y' to try again,any other key to exit)";
		read i;
	else
		i='n';
		echo " ";
		echo "Login Successful";
	fi  
	
done
