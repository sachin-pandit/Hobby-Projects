
hash=`./a.out pass35`

if [ -f temp ]
then
	rm temp
fi
curl http://localhost/xampp/php/register.php > temp

pub=`awk "NR==164" temp`


if [ -f log_temp ]
then
	rm log_temp
fi
echo "login"
curl http://localhost/xampp/php/login.php > log_temp

a=`awk "NR==160" log_temp`


y=`echo $pub^$hash%10000000000 | bc`

rand="$RANDOM"
rand=`echo $rand%45 | bc`
rand=`echo $rand+500	 | bc`

c=`echo "($y+ $pub^$rand +$a)%15" | bc`

z=`echo $rand-$c*$hash | bc`


echo "user35"
echo "c = $c"
echo "z = $z"
echo "a = $a"
echo "pub = $pub"

curl -d username="user35" -d cvalue="$c" -d zvalue="$z" -d a="$a" -d public="$pub" -d submit="Submit" 'http://localhost/xampp/php/login_verify.php' 
