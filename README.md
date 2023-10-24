# AED1G135
Group Project 1 for AED

#  #TODO
1. Read and parse the given data. This includes loading the parsed data into the data structures that are
   most appropriate for the required functionalities. Pay close attention to the linear and hierarchical
   data structures that you select for each scenario so that you can leverage each data structure’s
   advantages and drawbacks appropriately.
2. Develop a schedule management system. The system must incorporate a comprehensive set of
   functionalities of schedule management, including those specified for this project and any others
   deemed relevant. It must have a user-friendly menu enabling users to define their desired criteria.
   The menu must show available functionalities and their corresponding outputs in a clear, organized,
   and logical manner, facilitating seamless program utilization and straightforward result
   interpretation.
3. Perform several listings of the data, both in a total or partial manner. Take into consideration that
   the user may wish to obtain filtered information from the system. In this sense, it is also important
   that the listed information be sorted in a logical manner, so as to further facilitate the use of the
   program. As a source of inspiration, you may consider the following listings:

    i.Consult the schedule of a given student or class;

    ii.Consult the students within a given class, course or year; 

    iii.Consult the number of students registered in at least n UCs;

    iv.Consult the class/year/UC occupation (sorting by UC, ascending or descending order, …);

    v.Consult the UCs with the greatest number of students;

    vi.…

4. Process requests for new registrations or updates to existing registrations. Consider that students 
   may need to register for a UC or class change. These requests must be analyzed before acceptance
   and therefore, they must be stored in appropriate data structures to process either one request at a
   time or all at once.
   Requests can have three different types: add, remove or switch. An add/remove request occurs
   when a student wants to join/leave either an UC or a class. Finally, a switch request enables
   students to trade an UC or a class where they were previously registered by a new UC or class.

   i.
   For UC changes, consider the following rules:
       1. A student cannot be registered in more than 7 UCs at any given time;
       2. There must be at least one class with a vacancy in the new UC;
       3.The resulting schedule will not conflict with the student’s original schedule.
   ii.
   For class changes, consider the following rules:
       1. A student cannot be in more than one class at once for a given UC;
       2. A class can only accept a new student if its capacity has not been exceeded. Consider that there is a maximum capacity Cap for classes;
       3. A class can only accept a new student if the balance between class occupation is
          not disturbed. The balance of class occupation is maintained when the difference
          between the number of students in any class is less than or equal to 4;
       4. There is no conflict between the student’s schedule and the new class’s schedule.
5. Maintain a chronological record of all changes made to the system. The system must store accepted
   requests in the order they were processed, enabling users and administrators to easily undo the most
   recent actions. Take into consideration that undoing some requests may violate the aforementioned
   rules, making the undo operation impossible. In these cases, the undo request must be denied and
   its record removed from the system.
6. Include documentation for the most relevant functions that you implemented, generated using
   Doxygen. Indicate the time complexity of the most relevant functions or algorithms of your
   program.