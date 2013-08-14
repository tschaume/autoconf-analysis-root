#!/bin/sh

sed -n '47p' refman_mod.tex
newline=$(sed -n '46p' refman.tex | sed 's#\\#\\\\#g')
echo $newline
sed "47c\\
$newline
" refman_mod.tex > tmp.tex
mv tmp.tex refman_mod.tex
sed -n '47p' refman_mod.tex
echo ========================
sed -n '51p' refman_mod.tex
newline=$(sed -n '50p' refman.tex | sed 's#\\#\\\\#g')
echo $newline
sed "51c\\
$newline
" refman_mod.tex > tmp.tex
mv tmp.tex refman_mod.tex
sed -n '51p' refman_mod.tex
