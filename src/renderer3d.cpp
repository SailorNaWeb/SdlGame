#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Renderer3D {
    public:

	void addPoligon(Poligon* poligon) {
	    
	    if (vertex == NULL) {

		vertex = (float*)malloc(poligon->getVertexQnt() * 7 * sizeof(float));
		
		memcpy(vertex, poligon->getVertex(), poligon->getVertexQnt() * 7);

		vertex_size = poligon->getVertexQnt();
	    } else {
		
		int new_vertex_size = vertex_size + poligon->getVertexQnt();

		float* tempPointer = (float*)realloc(vertex,  new_vertex_size * 7);
		vertex = tempPointer;

		tempPointer = vertex + vertex_size * 7 + 1;
		memcpy(tempPointer, poligon->getVertex(), poligon->getVertexQnt() * 7);
	    
		vertex_size = new_vertex_size;
	    }

	    if (objects == NULL) {
		objects_size = 0;

		objects = (int*)malloc(sizeof(int));
	    } else {
		int* tempPointer = (int*)realloc(objects, objects_size + 1);

		objects = tempPointer;
	    }

	    objects[objects_size] = vertex_size - poligon->getVertexQnt();

	    poligon->index = objects_size;

	    objects_size++;
	}

	void removePoligon(Poligon* poligon) {
	    

	}

	void render() {

	}

    private:
	float* vertex;
	int vertex_size;
	
	int* objects;
	int objects_size;

	char* vertex_shader;
	char* fragment_shader;
}
