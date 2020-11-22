FROM centos:8.1.1911

COPY ./mem-alloc/mem_alloc /
COPY ./read-file/read_file /

CMD ["/read_file", "/mnt/test.file", "100"]
