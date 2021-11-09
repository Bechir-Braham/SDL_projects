CFLAGS = -I include -lSDL2
 

src = $(wildcard src/*.cpp)
obj = $(patsubst src/%.cpp, obj/%.o, $(src))
headers = $(wildcard include/*.h)


quicksort: print $(obj)
	g++ $(CFLAGS)  $(obj) -o quicksort

print:
	$(info	source files: $(src))
	$(info	headers: $(headers))
	$(info	object files: $(obj))

 
obj/%.o: src/%.cpp $(headers) | obj
	g++ $(CFLAGS) -c $< -o $@

obj:
	mkdir -p $@

clean:
	rm obj/* quicksort
all: quicksort
