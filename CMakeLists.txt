cmake_minimum_required(VERSION 3.27)
project(PkLib C)

set(CMAKE_C_STANDARD 17)
include_directories(Lib)

set(SOURCES
        main.c
        Lib/DataStructures/Basic/Node/Node.c
        Lib/DataStructures/Lists/LinkedList/LinkedList.c
        Lib/DataStructures/Lists/Queue/Queue.c
        Lib/DataStructures/Lists/Stack/Stack.c
        Lib/DataStructures/Trees/BST/BinarySearchTree.c
        Lib/DataStructures/Basic/Node/TreeNode.c
        Lib/DataStructures/Trees/AVLTree/AVLTree.c
        Lib/System/ThreadPool/ThreadPool.c
)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
        pthread
)
