FROM python:3.11-slim
WORKDIR /usr/src/app
COPY app/requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt
COPY app/ .
ENV PYTHONUNBUFFERED=1
RUN python manage.py collectstatic --noinput
EXPOSE 8000
CMD ["gunicorn", "proyecto.wsgi:application", "--bind", "0.0.0.0:8000"] 