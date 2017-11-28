rm $1
clear
echo "Compiling..."
g++ -O2 -o $1 $1.cpp -std=c++11
echo "Done.."
time ./$1 < $1.in > $1.out
echo ""
echo "============Running=============="
cat $1.out
echo "============Finished============="
echo ""
