read: read.cpp
	g++ read.cpp -o read -lboost_system -lboost_filesystem
all: read

agg: agg.cpp
	g++ -g agg.cpp -o agg -lboost_system -lboost_filesystem
