
rm $1
clear
echo "Compiling $1/$1.cpp..."
g++ -O2 -o $1/$1 $1/$1.cpp -std=c++11 -w
echo "Done.."
time ./$1/$1 < $1/$1.in > $1/$1.out
echo ""
echo "============Running=============="
cat $1/$1.out
echo "============Finished============="
echo ""
