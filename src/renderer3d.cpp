#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <poligon.h>

class Renderer3D {
    public:

	void addPoligon(Poligon* poligon) {
	    
	    if (poligonos == NULL) {
		
		poligonos = malloc(sizeof(Poligon*));

		poligonos[0] = poligon;

		poligonos_size = 1;

		poligon->index = poligonos_size - 1;
	    } else {

		Poligon* array_temp = realloc(poligonos, ++poligonos_size);

		poligonos = array_temp;

		poligonos[poligonos_size - 1] = poligon;

		poligon->index = poligonos_size - 1;
	    }
	}

	void removePoligon(Poligon* poligon) {
	    for (int i = poligon->index; i < poligonos_size - 1; i++) {
		poligonos[i] = poligonos[i + 1];
		poligonos[i]->index--;
	    }

	    Poligon* array_temp = realloc(poligonos, --poligonos_size);

	    poligonos = array_temp;
	   
	}

	void render() {

	}

    private:
	Poligon* poligonos;
	int poligonos_size;

	char* vertex_shader;
	char* fragment_shader;
}
