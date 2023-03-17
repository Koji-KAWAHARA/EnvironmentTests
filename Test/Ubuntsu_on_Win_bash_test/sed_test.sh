list=("1" "2" "3")
target_text="sed_test_target.txt"
for name in $list;do
    echo $name
    echo "sed -i "s@^IOfolder=*@IOfolder='$name'@" $target_text"
    sed -i "s@^IOfolder=*@IOfolder='$name'" $target_text
    echo `cat $target_txt`
done