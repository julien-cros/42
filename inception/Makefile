.PHONY: build up start down destroy stop restart logs ps

build:
	docker compose -f srcs/docker-compose.yml build
up:
	docker compose -f srcs/docker-compose.yml up -d
down:
	docker compose -f srcs/docker-compose.yml down
destroy:
	docker compose -f srcs/docker-compose.yml down -v
	docker system prune -af
	sudo rm -rf /home/jcros/data/mariadb/*
	sudo rm -rf /home/jcros/data/wordpress/*
stop:
	docker compose -f srcs/docker-compose.yml stop
restart:
	docker compose -f srcs/docker-compose.yml stop
	docker compose -f srcs/docker-compose.yml up -d
logs:
	docker compose -f srcs/docker-compose.yml logs
ps:
	docker compose -f srcs/docker-compose.yml ps
volume:
	docker volume ls
