package main

import (
	"fmt"
	"io"
	"os"
	"time"
)

const DUBUFSIZE  = 4096
const WRITEBUFSIZE  = (64 * 1024)

var durationBuf[DUBUFSIZE] time.Duration
func main() {
	if len(os.Args) != 3 {
		fmt.Printf("Usage: app <input_filename> <output_filename>")
	}

	//time.Sleep(20 * time.Second)
	// open input file
	fi, err := os.Open(os.Args[1])
	if err != nil {
		panic(err)
	}
	// close fi on exit and check for its returned error
	defer func() {
		if err := fi.Close(); err != nil {
			panic(err)
		}
	}()

	// open output file
	fo, err := os.Create(os.Args[2])
	if err != nil {
		panic(err)
	}
	// close fo on exit and check for its returned error
	defer func() {
		if err := fo.Close(); err != nil {
			panic(err)
		}
	}()

	// make a buffer to keep chunks that are read
	buf := make([]byte, WRITEBUFSIZE)
	i := 0
	for {
		i = i % DUBUFSIZE
		// read a chunk
		n, err := fi.Read(buf)
		if err != nil && err != io.EOF {
			panic(err)
		}
		if n == 0 {
			break
		}
		before := time.Now()
		// write a chunk
		if _, err := fo.Write(buf[:n]); err != nil {
			panic(err)
		}

		durationBuf[i] = time.Since(before)
		i++
	}

	for i = 0; i < DUBUFSIZE; i++ {
		if durationBuf[i] == 0 {
			continue
		}
		fmt.Print(i, ": ", durationBuf[i], "\n")
	}
}
