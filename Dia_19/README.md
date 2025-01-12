# Día 19

Hemos elegido este día para aplicar las tablas hash y programación dinámica.

A pesar de que se puede resolver de otras formas, hemos optado por usar tablas hash. Usaremos una tabla hash para almacenar todas los patrones de colores que tenemos, de forma que resultará más fácil encontrar si existe uno que se ajuste a lo que queremos o no. En este caso la propia clave que usamos es el dato que querremos así que podemos prescindir de la variable valor, de todas formas las dejamos por si nos sirviera en un futuro. Las entradas de la tabla y la clase tabla hash estásn en un archivo .h adjunto en la carpeta.

Los pasos seguidos para resolver la parte 1 han sido:
- Crear una clase tabla hash y tableentry. En la tabla hash almacenaremos todas las toallas que tenemos para combinar.
- Cada vez que queremos comprobar una toalla hay que buscarla en la tablas hash, que nos ahorra mucho tiempo frente a buscarlo linealmente en un vector.
- Creamos una función recursiva encargada de buscar según la combinación la toalla necesaria, en caso de no haber, busca si hay una toalla que siga la combinación pero incluyendo el siguiente color.
- Nos hemos visto obligados a usar programación dinámica en este punto dado que el código tardaba demasiado en ejecutarse, y hemos añadido una memoria que evita tener que estar calculando los mismo procesos siempre. 

Solo hace falta compilar y ejecutar el código. Los datos del problema se extraen automáticamente de un archivo .txt llamado datos.