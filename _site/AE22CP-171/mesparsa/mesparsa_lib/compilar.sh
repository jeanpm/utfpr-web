CAPACIDADE=10

gcc -c -fPIC mesparsa_encadeada.c lista/qlist.c -DCAPACIDADE=$CAPACIDADE

gcc -c -fPIC mesparsa_hash.clista/dlist.c        -DCAPACIDADE=$CAPACIDADE



libname="libmesparsa.so"

gcc -shared -o  $libname.list           mesparsa_encadeada.o    qlist.o

gcc -shared -o  $libname.hash           mesparsa_hash.o         dlist.o

rm $libname
ln -s $libname.list $libname

libdir=`pwd`

gcc -L$libdir -Wall mesparsa_main.c -o main -lmesparsa      -DCAPACIDADE=$CAPACIDADE


export LD_LIBRARY_PTH=$libdir:$LD_LIBRARY_PATH
