CFLAGS = -I include -lSDL2
 

src = $(wildcard src/*.cpp)
obj = $(patsubst src/%.cpp, obj/%.o, $(src))
headers = $(wildcard include/*.h)


bubble_sort: print $(obj)
	g++ $(CFLAGS)  $(obj) -o bubble_sort

print:
	$(info	source files: $(src))
	$(info	headers: $(headers))
	$(info	object files: $(obj))

 
obj/%.o: src/%.cpp $(headers) | obj
	g++ $(CFLAGS) -c $< -o $@

obj:
	mkdir -p $@

clean:
	rm obj/* bubble_sort
all: bubble_sort
