# Install

See the [install](https://bitbucket.org/osrf/swarm/wiki/Install.md) instructions.

# Tutorials

See the [Swarm wiki home page](https://bitbucket.org/osrf/swarm/wiki/Home).

# API

  [Doxygen](https://s3.amazonaws.com/osrf-distributions/swarm/api/0.1.0/index.html)

# Test worlds

1. `gazebo worlds/ground_simple_2.world`

    This will run a sample world with 2 ground vehicles.

1. `gazebo worlds/fixed_simple_36.world`

    This will run a sample world with 36 fixed wing aircraft.

1. `gazebo worlds/rotor_simple_36.world`

    This will run a sample world with 36 rotorcraft.

1. `gazebo worlds/ground_simple_36.world`

    This will run a sample world with 36 ground vehicles.


[Resumen del paper](https://sfi-edu.s3.amazonaws.com/sfi-edu/production/uploads/sfi-com/dev/uploads/filer/8a/2a/8a2ae001-9ad5-43e6-b7e3-4d951223e9e8/96-06-042.pdf)

# The Swarm Simulation System: A Toolkit for Building Multi-Agent Simulations

El documento titulado "The Swarm Simulation System: A Toolkit for Building Multi-Agent Simulations" presenta un sistema de simulación orientado a la construcción de simulaciones de sistemas complejos y adaptativos mediante el uso de agentes autónomos. Este proyecto fue desarrollado en el Instituto Santa Fe en colaboración con ingenieros de software y científicos, y se posiciona como una herramienta estándar que facilita la creación de modelos, la experimentación y el análisis de simulaciones, con el objetivo de abordar algunas de las dificultades típicas asociadas con la modelación computacional.

## Introducción al Sistema Swarm

Swarm es un sistema multiagente que se utiliza para simular sistemas adaptativos complejos. Su concepto central es el "enjambre" (swarm), que consiste en una colección de agentes que ejecutan un cronograma de acciones. El sistema permite la simulación de modelos jerárquicos, donde los agentes pueden estar compuestos por enjambres de otros agentes organizados en estructuras anidadas. Swarm ofrece bibliotecas orientadas a objetos que incluyen componentes reutilizables para construir modelos, analizar datos, controlar experimentos y visualizar resultados.

Swarm fue desarrollado con el objetivo de ofrecer un conjunto estandarizado de herramientas de software para la experimentación científica, permitiendo a los científicos enfocarse más en la investigación que en la construcción del equipamiento experimental. Swarm está disponible como una versión beta con código fuente abierto, y requiere el compilador GNU C, Unix y X Windows.

## Formalismo Multiagente y Componentes Jerárquicos

Swarm adopta un formalismo de simulación basado en agentes autónomos que interactúan mediante eventos discretos. No se hacen suposiciones específicas sobre el tipo de modelo a implementar; es decir, no se establecen requisitos específicos de dominio, como entornos espaciales, fenómenos físicos o patrones de interacción específicos. Este enfoque le otorga gran flexibilidad, permitiendo la aplicación de Swarm en ámbitos tan diversos como la química, economía, física, antropología, ecología y ciencia política.

El concepto básico de simulación en Swarm es el agente, definido como cualquier actor que puede generar eventos que afecten a otros agentes. Cada simulación está compuesta por grupos de agentes que interactúan mediante eventos programados. Además, los enjambres pueden contener otros enjambres, lo cual permite la construcción de modelos jerárquicos, en los que se pueden definir diferentes niveles de interacción. Por ejemplo, un modelo de ecosistema puede contener un enjambre que represente un estanque con organismos unicelulares, mientras que cada organismo se puede modelar como un enjambre compuesto de orgánulos.

## Tecnología Orientada a Objetos y Arquitectura del Sistema

Swarm está implementado utilizando tecnología orientada a objetos (OO) con el lenguaje Objective-C. La programación orientada a objetos resulta conveniente para la construcción de bibliotecas de software reutilizables, ya que facilita la especialización de clases mediante herencia. En Swarm, cada agente se implementa como un objeto, donde las clases de agentes definen el comportamiento genérico y los objetos individuales representan agentes específicos. Las variables de instancia almacenan el estado de los agentes, mientras que los métodos definen sus acciones.

Swarm también incluye una característica denominada "probes", que permite observar y modificar el estado de los objetos de forma genérica. Esta capacidad es útil para realizar análisis de datos en tiempo real y facilita la evaluación y reproducción de resultados. Además, Swarm proporciona herramientas para separar el modelo de la recolección de datos mediante el uso de agentes observadores, lo cual ayuda a mantener el modelo puro y autocontenido, facilitando la replicabilidad de los experimentos.

## Bibliotecas de Swarm

Swarm está compuesto por varias bibliotecas que cumplen diferentes funciones en el proceso de modelado y simulación. Las bibliotecas principales incluyen:

- **swarmobject**: Proporciona las clases básicas para los agentes y los enjambres.
- **activity**: Contiene las estructuras de datos necesarias para programar y ejecutar los eventos de la simulación.
- **simtools**: Incluye herramientas para la ejecución de simulaciones y el análisis de datos, como gráficos de series temporales y estadísticas.
- **random**: Proporciona generadores de números aleatorios para simulaciones, asegurando la independencia de las secuencias de números aleatorios, lo cual es crucial para la repetibilidad de los experimentos.
- **tkobjc**: Es una biblioteca para la interfaz de usuario basada en Tcl/Tk, que permite la visualización de los resultados y la interacción con el modelo.

Además, Swarm incluye bibliotecas específicas de dominio, como **space** (para el modelado de espacios bidimensionales), **ga** (para algoritmos genéticos) y **neuro** (para redes neuronales). Estas bibliotecas permiten extender la funcionalidad de Swarm y facilitar la construcción de modelos complejos.

## Comunidad de Usuarios y Futuro de Swarm

Swarm fue concebido como un servicio para la comunidad de investigadores interesados en la simulación de sistemas complejos. La distribución inicial se lanzó en octubre de 1995 y, desde entonces, varios grupos de usuarios han comenzado a crear modelos utilizando la plataforma. Uno de los objetivos principales es promover la colaboración y el intercambio de código y técnicas de modelado dentro de la comunidad científica, fomentando una forma importante de intercambio intelectual.

El documento también menciona que el desarrollo de Swarm continuará para ofrecer una versión estable y bien documentada. A largo plazo, se busca construir una comunidad de modeladores que puedan compartir componentes y bibliotecas, promoviendo la especificación estándar de los programas computacionales utilizados como herramientas en la investigación experimental.

## Conclusión

Swarm es una herramienta innovadora para la simulación de sistemas complejos mediante agentes. Ofrece una infraestructura flexible y reutilizable, soportada por un conjunto de bibliotecas bien diseñadas que facilitan la construcción de modelos complejos, así como su análisis y reproducción. La separación entre los modelos y los mecanismos de recolección de datos permite mantener los modelos autocontenidos y aumentar la reproducibilidad de los experimentos. En última instancia, Swarm pretende ser un catalizador para una comunidad de investigadores interesados en la experimentación científica con sistemas complejos, proporcionando una plataforma estandarizada que favorezca la colaboración y el intercambio de conocimiento.

