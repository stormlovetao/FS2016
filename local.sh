#!/bin/bash
cd /Users/tao/FS2016_10/OurESURemoveD
for size in $(seq 10 5 100);do
	./OurESU -i networks/ecoli  -d 2 -u -l 10000000 -s $size > ./exp4/${size}.txt
done

# cd /Users/tao/FS2016_10/QuateXelero
# for size in $(seq 45 5 100);do
# 	./QuateXelero -i networks/ecoli -u -l 10000000 -s $size > ${size}.txt
# done


