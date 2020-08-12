for val in  ./*
do
    if[$val -ne 1]:then
        echo "$i" | "$val"/a.out
    echo "\n" | cat -e
done