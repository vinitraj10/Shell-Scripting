echo "Enter a Number:-"
read num
i=1
while [ $i -le 5 ]
do
  val= $(expr $i \* $n)
  echo $val
  i=$(( $i + 1 ))
  val=0

done
