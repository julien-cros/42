THIS_FILE := $(lastword $(MAKEFILE_LIST))
.PHONY: build up start down destroy stop restart logs logs-api ps login-timescale login-api db-shell

build:
	docker compose -f srcs/docker-compose.yml build $(c)
up:
	docker compose -f srcs/docker-compose.yml up -d $(c)
down:
	docker compose -f srcs/docker-compose.yml down $(c)
destroy:
	docker compose -f srcs/docker-compose.yml down -v $(c)
	docker system prune -af $(c)
stop:
	docker compose -f srcs/docker-compose.yml stop $(c)
restart:
	docker compose -f srcs/docker-compose.yml stop $(c)
	docker compose -f srcs/docker-compose.yml up -d $(c)
logs:
	docker compose -f srcs/docker-compose.yml logs --tail=100 -f $(c)
ps:
	docker compose -f srcs/docker-compose.yml ps
volume:
	docker volume ls