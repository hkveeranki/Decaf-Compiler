#!/bin/bash
IR_FILE='IR_tmp'
OUT_FILE='output_tmp'
OUT_DIR='outputs'
LLI=lli
if [ "$#" -lt 1 ]; then
	BINARY='../build/bin/decafCompiler'
else
	BINARY=$1
fi
if [ ! -f $BINARY ]; then
	echo "Binary file doesn't exist, provide a valid compiler binary"
else
	for i in `ls *.dcf`
	do
		## Generate the llvm IR code using decafCompiler
		$BINARY $i > $IR_FILE
		## Run the IR code using lli, the llvm ir executor
		printf "\n-------------- Executing the IR and generating the output ------------------\n"
		$LLI $IR_FILE > $OUT_FILE
		## Compare the output to the test output
		
		diff "$OUT_FILE" $OUT_DIR/"$i"_output 
		if [ $? -eq 0 ]; then
			echo "Test for $i passed"
		else
			echo "Test for $i failed. Outputs doesn't match"
		fi
	done
	rm $IR_FILE $OUT_FILE -f
fi
