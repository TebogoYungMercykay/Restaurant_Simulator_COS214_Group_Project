# Restaurant Simulator/Restaurant Tycoon Game

Welcome to the Restaurant Simulator/Restaurant Tycoon Game project! This assignment challenges you to design a restaurant simulation software, where you can model the intricate processes of running a restaurant, from seating customers to serving food, and even expand it into a "restaurant tycoon" game if desired.

In a restaurant, numerous processes happen simultaneously, resulting in the production and sale of food to customers. This project mainly focuses on two distinct areas: the floor (front of house) and the kitchen (back of house). Both areas need to communicate effectively to ensure a seamless dining experience.

## Project Features

- **Customer Management**: Customers can request seating, and if tables are available, they are assigned a table, mimicking a Maitre D showing them to their seats.
- **Order Management**: Customers can place orders through waiters. Orders are then sent to the kitchen for preparation.
- **Table Management**: Floor staff manage tables, combining or splitting them as needed to accommodate various party sizes.
- **Booking System**: The restaurant can have a booking system or walk-in service. Waiters are assigned specific tables to manage.
- **Customer Satisfaction**: Managing customer expectations is vital. Satisfied customers might tip more, while unhappy customers may complain.
- **Custom Orders**: Customers can create custom orders from a list of available options and specify preparation methods.
- **Tab System**: Customers can start a tab and pay their bill at a later date.
- **Kitchen Chaos**: The kitchen is where most of the chaos occurs. Different chefs are responsible for various parts of the preparation process.
- **Order Workflow**: Orders are passed between different stations in the kitchen before being plated and sent to the customer via the waiter.
- `Additional Features`: You might extend the design to include a bar with cocktails, valet service, inventory and accounting for a more detailed restaurant tycoon experience.

## Project Architecture

- ### The Floor

  The floor represents the front of the restaurant where customers are seated and managed. It involves:


  - Seating customers and assigning them tables
  - Taking customer orders through waiters
  - Managing table assignments and customer expectations
  - Handling the payment process, including bill splitting.
  - Allotting tables to waiters for management.
- ### The Kitchen

  The kitchen is the back of the restaurant where food preparation takes place. Key aspects include:


  - Receiving orders from waiters
  - Assigning tasks to different chefs based on the order
  - Passing dishes between various stations for preparation
  - Final plating by the head chef
  - Notifying waiters when orders are ready for delivery.

## Additional Instructions

To enhance the project, We might consider adding more features:

- **Bar**: Implement a bar with various cocktails and manage drink orders.
- **Valet Service**: Include a valet service for customers to add a touch of luxury.
- **Inventory and Accounting**: Implement inventory management and accounting systems for a comprehensive restaurant tycoon experience.

## Quick Summary - Design Patterns

The focus will be on reusable software patterns for modeling classes and their relationships. To visually understand the software models, UML will be used.

<img src="./Images/UML_Random.png" alt="UML Random" width="100%">

- ### `Introduction`:

  - ##### What are Design Patterns?:

    Design patterns are proven solutions to recurring design problems in software engineering. They offer guidelines and templates for solving common challenges while promoting best practices and maintainable code.
  - ##### Benefits of Design Patterns:

    - Reusability: Patterns provide reusable solutions to common problems, saving time and effort.
    - Consistency: They establish a common vocabulary and structure, improving code readability and maintainability.
    - Flexibility: Patterns make code more adaptable to changes, reducing the impact of modifications.
    - Scalability: They help manage complexity, enabling smooth system growth.
  - ##### Types of Design Patterns:

    - Creational Patterns: Focus on object creation mechanisms, offering flexible
      ways to instantiate objects.
    - Structural Patterns: Deal with the composition of classes or objects,
      emphasizing the organization of components.
    - Behavioral Patterns: Handle communication between objects and
      responsibilities, managing interactions.
  - ##### Examples of Classic Design Patterns:

    - Creational Patterns: Singleton, Factory Method, Abstract Factory, Builder, Prototype.
    - Structural Patterns: Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy
    - Behavioral Patterns: Chain of Responsibility, Command, Interpreter, Iterator, Mediator, Memento, Observer, State, Strategy, Template Method, Visitor.
  - ##### When to Use Design Patterns:

    - When facing common problems that have known solutions.
    - When aiming for code that's more maintainable, extensible, and easier to understand.
    - When collaborating on a project and needing a common language for communication.
    - When designing a software architecture that can accommodate future changes.
  - ##### Considerations:

    - `Not a One-Size-Fits-All`: Choose patterns based on the specific problem and context.
    - `Overuse`: Don't apply patterns just for the sake of it; simplicity is valuable.
    - `Learning Curve`: Understand the patterns thoroughly before applying them.
    - `Evolution`: Patterns evolve over time with the advent of new technologies and practices.
- ### `Inter-Relationships`:

  - Many patterns can work together, and patterns can complement each other in solving complex design challenges.
  - Understanding the relationships between patterns enhances your ability to choose and apply them effectively.
- ### `Classic Design Patterns`:

  - ##### Structural Patterns (Organization and Composition):

    - `Adapter:` Convert the interface of a class into another interface clients expect.
    - `Bridge:` Decouple an abstraction from its implementation, allowing both to vary
      independently.
    - `Composite:` Compose objects into tree structures to represent part-whole
      hierarchies.
    - `Decorator:` Dynamically add responsibilities to objects without altering their core
      structure.
    - `Facade:` Provide a unified interface to a set of interfaces in a subsystem.
    - `Flyweight:` Use sharing to support large numbers of fine-grained objects
      efficiently.
    - `Proxy:` Provide a surrogate or placeholder for another object to control access or
      add behavior.
  - ##### Behavioral Patterns (Communication and Interaction):

    - `Chain of Responsibility:` Avoid coupling the sender of a request to its receiver by
      giving more than one object a chance to handle the request.
    - `Command:` Encapsulate a request as an object, allowing parameterization of
      clients with different requests.
    - `Interpreter:` Provide a way to evaluate language grammar or expressions.
    - `Iterator:` Provide a way to access elements of a collection sequentially without
      exposing its underlying representation.
    - `Mediator:` Define an object that encapsulates how a set of objects interact,
      promoting loose coupling.
    - `Memento:` Capture an object's internal state to be able to restore it later.
    - `Observer:` Define a one-to-many dependency between objects, so that when
      one object changes state, its dependents are notified and updated.
    - `State:` Allow an object to alter its behavior when its internal state changes.
    - `Strategy:` Define a family of algorithms, encapsulate each one, and make them
      interchangeable.
    - `Template Method:` Define the structure of an algorithm in a superclass but allow
      subclasses to override specific steps.
    - `Visitor:` Represent an operation to be performed on elements of an object
      structure without changing their classes.
  - ##### Creational Patterns (Object Creation Mechanisms):

    - `Abstract Factory:` Provide an interface for creating families of related or
      dependent objects without specifying their concrete classes.
    - `Builder:` Separate the construction of a complex object from its representation,
      allowing the same construction process to create different representations.
    - `Factory Method:` Define an interface for creating objects, but let subclasses
      decide which class to instantiate.
    - `Prototype:` Specify the kinds of objects to create using a prototypical instance,
      and create new objects by copying this prototype.
    - `Singleton:` Ensure a class has only one instance and provide a global point of
      access to it.
- ### `Inter-Relationships`:

  - Many patterns can work together. For instance, an Abstract Factory might use Factory Methods to create objects.
  - Decorator and Adapter patterns can be used together to add functionality to an object and change its interface.
- ### `Usage`:

  - Structural patterns organize classes and objects, managing how they are composed.
  - Behavioral patterns handle communication between objects and responsibilities.
  - Creational patterns manage object creation and initialization, controlling object instantiation.
- Remember, design patterns are tools in your software engineering toolbox. Their proper application depends on the specific problem you're solving, the architecture you're designing, and the goals you're aiming to achieve. Design patterns offer solutions to common design problems, fostering good software design practices and code organization. The choice of pattern depends on the problem you're addressing and the architecture you're designing.

## Getting Started With the Project

- Navigate to the `src/test` folder for detailed Information about the Project Usage and Implementation
  - `Testing Folder`: ./test/README.md
  - `Source Folder`: ./src/README.md
- The "src" directory of our "Restaurant Simulator" project is where the actual implementation of our restaurant simulation code resides.
- The "test" directory is dedicated to testing our "Restaurant Simulator". In this folder, you'll find unit tests, integration tests, and test data to ensure the robustness and correctness of our Implementation

---

<p align="center">The End, Thank You</p>

---

---
