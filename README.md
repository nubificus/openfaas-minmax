# openfaas-minmax

This repo hosts an example minmax CPU operation for OpenFaaS.

### Input

The input is provided via a json file (needs libjansson) through STDIN. 

```
array,
rowcount
```

An example input file is produced by running:

```
./src/init > input.txt
```

### Output

The output is `min: , max: and outdata`,
also provided as a json file.

### Build as a standalone app

To build enter the src directory and type `make`. Two libraries and an
executable should be built:

```
libfileread.so
libminmax.so
test
```

To build as an OpenFaaS function from the root directory type:

```
docker build -t user/minmaxcpu:latest -f Dockerfile .
```

then push to the dockerhub:

```
docker push user/minmaxcpu:latest
```

and use the stack-minmax-cpu.yml to deploy to your openfaas installation:

```
faas-cli deploy -f stack-minmax-cpu.yml
```

Make sure to use your own gateway param, as well as your own openfaas profile
annotation.
