#shift = premier argument ?
#du coup @ARGV = tous les autres
perl -e 'alarm shift; exec @ARGV' "$@";
