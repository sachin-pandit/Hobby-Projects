
i=1;

if [ -f log_temp ]
then
	rm log_temp
fi

echo "login"
curl http://localhost/xampp/php/login.php > log_temp

a=`awk "NR==160" log_temp`

if [ -f temp ]
then
	rm temp
fi

echo "Register"
curl http://localhost/xampp/php/register.php > temp

pub=`awk "NR==164" temp`
hash=`./a.out pass1`

echo " "
y=`echo $pub^$hash%10000000000 | bc`

if [ $hash -lt 5 ]
then 
	rand="$RANDOM"
	rand=`echo $rand%10 | bc`
	rand=`echo $rand+60 | bc`
	echo "random value is $rand"
else
	rand="$RANDOM"
	rand=`echo $rand%10 | bc`
	rand=`echo $rand+135 | bc`
	echo "random value is $rand"
fi	


c=`echo "($y+ $pub^$rand +$a)%15" | bc`


z=`echo $rand-$c*$hash | bc`

echo "Y value is $y"
echo "A value is $a"
echo "The value of z is $z"
echo "hash = $hash"
echo "public key is $pub"
echo "The value of c is $c"


c1=`echo "($y + ($y^$c)*($pub^$z) + $a) % 15" | bc`
echo "C1 value is $c1"	
