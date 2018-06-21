#!/usr/bin/python
import fcntl
import time
def main():
    file_path = "/mnt/disrep_tier/lock/file"
    FH = open(file_path, "rw+")
    print FH
    try:
      fcntl.lockf(FH, fcntl.LOCK_EX, 10, 10, 0)
    except IOError:
       print "lock could not be held."
       return False
    print "lock held"
    time.sleep(3000)
    return True
if __name__ == "__main__":
   main()
