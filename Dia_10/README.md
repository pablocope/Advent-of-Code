# Día 10

Hemos elegido este día para aplicar los grafos.

A pesar de que se puede resolver de otras formas, hemos optado por usar grafos. Lo hemos enfocado de forma que cada casilla del mapa sea un nodo del grafo pero que luego solo se unan entre sí las que cumplen la condición para ser un camino hasta la cima. De esta forma solo tendremos que recorrer el grafo empezando por el nodo con altura 0 y contar a cuantos nodos con altura nueve podemos llegar desde ahí.

Los pasos seguidos para resolver la parte 1 han sido:
- Crear una clase grafo con su respectiva clase nodo. La clase grafo contiene una lista con todos los nodos y una lista de adyacencia para saber como se unene entre sí. Además hemos incluido en el grafo el mapa en el que se basa para facilitar un poco la creación del grafo. También hemos incluido funciones básicas como obtener los datos, rellenar el grafo, imprimir variables...
- Hemos creado una función para encontrar nodos con alturas condretas y la hemos combinado con otra que busca el camino de un nodo a otro de altura 9 y retorna cuantas alturas 9 se han alcanzado.
- Para poder recorrer todo el grafo hemos aplicado lo anterior en una función recursiva.

Para la parte dos nos dimos cuenta qe tal y como lo teníamos hecho, sólo teníamos que eliminar la condición de no pasar por nodos ya visitados que habíamos puesto en la función recursiva de la parte 1. Por lo tanto, si se quiere comprobar la parte dos del problema simplemente hay que eliminar las líneas que se indican en un comentario que se deben eliminar para la parte 2.

Solo hace falta compilar y ejecutar el código. Los datos del problema se extraen automáticamente de un archivo .txt llamado datos.