./a.out $1 | sed -n '/digraph/,/}/p' >$1.dot
dot -T$2 $1.dot -o $1.$2
evince $1.$2