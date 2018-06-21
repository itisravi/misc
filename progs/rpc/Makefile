.SUFFIXES:
.SUFFIXES: .c .o
CLNT = list_clnt
SRVR = list_svc
CFLAGS = -g -Wall

SRVR_OBJ = list_svc_proc.o list_xdr.o list_svc.o
CLNT_OBJ = list_clnt_proc.o list_xdr.o list_clnt.o

.c.o:; gcc -c -o $@ $(CFLAGS) $<

default: $(CLNT) $(SRVR)

$(CLNT): $(CLNT_OBJ)
	gcc -o $(CLNT) $(CLNT_OBJ)

$(SRVR): $(SRVR_OBJ)
	gcc -o $(SRVR) $(SRVR_OBJ)

clean:
	rm *.o $(CLNT) $(SRVR)

