𝘛𝘩𝘪𝘴 𝘱𝘳𝘰𝘫𝘦𝘤𝘵 𝘩𝘢𝘴 𝘣𝘦𝘦𝘯 𝘤𝘳𝘦𝘢𝘵𝘦𝘥 𝘢𝘴 𝘱𝘢𝘳𝘵 𝘰𝘧 𝘵𝘩𝘦 42 𝘤𝘶𝘳𝘳𝘪𝘤𝘶𝘭𝘶𝘮 𝘣𝘺 <𝘧𝘴𝘩𝘦𝘭𝘯𝘢>

# OVERVIEW
Get Next Line e'progetto in cui si deve leggere da un File Descriptor e ritornare una riga dal File Descriptor

- Loop finche lo static buffer non contiene un '\n' 
- Finche non e' presente il '\n' il buffer su cui ho letto viene aggiunto allo static buffer
- Nel mentre controllo anche se sono arrivato alla fine del file (EOF)
- Una volta che il '\n' e' trovato ottengo la frase che verra ritornata
- Dopo modifico il buffer per elimanre la frase che ritorniamo 

# INSTRUCTIONS 

- cc -Wall -Werror -Wextra -DBUFFER_SIZE=n get_next_line.c get_next_line_utils.c // compilazione base
- cc -Wall -Werror -Wextra -DBUFFER_SIZE=n get_next_line_bonus.c get_next_line_utils_bonus.c // compilazione bonus
  

# RESOURCES 
- https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/
- https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/
- https://www.ibm.com/docs/en/aix/7.1.0?topic=volumes-using-file-descriptors
