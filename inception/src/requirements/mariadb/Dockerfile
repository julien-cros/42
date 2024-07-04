FROM debian:12

RUN apt update && apt upgrade -y && apt install -y mariadb-server

COPY conf/my.cnf /etc/mysql/my.cnf
RUN chmod 644 /etc/mysql/my.cnf

# COPY conf/init.sql /etc/mysql/init.sql
COPY ./tools/init.sh /usr/local/bin/init.sh
# RUN chmod 644 /etc/mysql/init.sql
RUN chmod +x /usr/local/bin/init.sh

RUN mkdir /run/mysqld
# RUN chown mysql:mysql /run/mysqld

ENTRYPOINT ["/usr/local/bin/init.sh"]

# EXPOSE 3306

CMD ["mysqld"]
# FROM alpine:3.20.0

# RUN apk update && apk add --no-cache mariadb mariadb-client 

# COPY conf/my.cnf /etc/mysql/my.cnf
# RUN chmod 644 /etc/mysql/my.cnf	

# RUN mkdir -p /var/run/mysqld /var/lib/mysql
# RUN chown -R mysql:mysql /var/run/mysqld /var/lib/mysql

# COPY ./tools/init.sh /usr/local/bin/
# COPY ./conf/init.sql /etc/mysql/init.sql
# RUN chmod 644 /etc/mysql/init.sql
# RUN chmod +x /usr/local/bin/init.sh

# # Ensure all MariaDB related files are owned by mysql user
# RUN chown -R mysql:mysql /etc/mysql

# ENTRYPOINT ["/usr/local/bin/init.sh"]

# EXPOSE 3306

# CMD ["mysqld", "--user=mysql", "--datadir=/var/lib/mysql"]
