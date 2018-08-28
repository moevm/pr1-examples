#!/bin/bash

for (( i=90; i > 0; i-=1 ))
do
  let "num = 10000+$RANDOM"
  let "num1 = 100+$RANDOM"
  let "num2 = 100+$RANDOM"
  touch "test.log.$num.zip"
  touch "test.log.$num-$num1.zip"
  touch "test.log.$num-$num1-$num2.zip"

  let "num = 1000+$RANDOM%9990"
  let "num1 = 10+$RANDOM%90"
  let "num2 = 10+$RANDOM%90"
  touch "test.log.$num1.zip"
  touch "test.log.$num-$num1.zip"
  touch "test.log.$num-$num1-$num2.zip"

done


