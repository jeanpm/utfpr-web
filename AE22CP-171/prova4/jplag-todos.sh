#/usr/bin/bash

entrada="codigos"
saida="html_comparacao"

rm -rf $saida

for dir in `ls $entrada`;
do
    mkdir $saida/$dir/
    java -jar jplag-2.11.9.jar $entrada/$dir/ -l c/c++ -r $saida/$dir/
done
