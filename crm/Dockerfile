FROM python:3.13.5-slim

ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1

WORKDIR /app

COPY requirements.txt /app/
RUN pip install --upgrade pip
RUN pip install -r requirements.txt

COPY . /app/

CMD ["sh", "-c", "python manage.py migrate && python manage.py collectstatic --noinput && gunicorn crm.wsgi:application --bind 0.0.0.0:8000"]
