## Установка и запуск

### 1. Клонирование репозитория

```bash
git clone <url>
cd test-drill-cloud-backend
```
### 2. Создание .env

Создать файл .env со следующими полями:

API_URL=                #Если сервер развёрнут в докере то не localhost, а host.docker.internal
INFRA_SECRET_KEY=       #INFRA_SECRET_KEY указанный в .env drill-cloud-backend

### 3. Сборка и запуск

```bash
docker build -t send-request-app .
docker run send-request-app
```
