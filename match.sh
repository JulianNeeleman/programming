mkdir match/$1

for ch in {a..l}
do
	mkdir match/$1/${ch}
	mkdir match/$1/${ch}/samples
	cp templates/main.cpp match/$1/${ch}/main.cpp
done
