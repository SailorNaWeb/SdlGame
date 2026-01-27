#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Renderer3D {
    public:

	void addCube(Cube* cube) {
	    
	}

	void removeCube(Cube* cube) {

	}

	void render() {

	}

    private:
	float* vertex;
	int vertex_size;
	int* objects;

	char* vertex_shader;
	char* fragment_shader;
}
