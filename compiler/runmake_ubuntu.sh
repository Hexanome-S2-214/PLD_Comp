# to get the required packages (ubuntu 21.10):
#   sudo apt install     antlr4 libantlr4-runtime-dev default-jdk
# the ANTLRJAR part below is copied from /usr/bin/antlr4

# Assign ANTLRLIB to either /usr/lib/x86_64-linux-gnu/libantlr4-runtime.a or /usr/lib/aarch64-linux-gnu/libantlr4-runtime.a depending on which exists.
if [ -f /usr/lib/x86_64-linux-gnu/libantlr4-runtime.a ]; then
    ANTLRLIB=/usr/lib/x86_64-linux-gnu/libantlr4-runtime.a
elif [ -f /usr/lib/aarch64-linux-gnu/libantlr4-runtime.a ]; then 
    ANTLRLIB=/usr/lib/aarch64-linux-gnu/libantlr4-runtime.a
elif [ -f /usr/lib64/libantlr4-runtime.a ]; then
    ANTLRLIB=/usr/lib64/libantlr4-runtime.a
else
    echo "Error: libantlr4-runtime.a not found"
    exit 1
fi

make \
    ANTLRJAR=/usr/share/java/stringtemplate4.jar:/usr/share/java/antlr4.jar:/usr/share/java/antlr4-runtime.jar:/usr/share/java/antlr3-runtime.jar/:/usr/share/java/treelayout.jar \
    ANTLRINC=/usr/include/antlr4-runtime \
    ANTLRLIB=$ANTLRLIB "$@"

