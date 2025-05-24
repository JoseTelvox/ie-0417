import os

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql',
        'NAME': os.getenv('DJANGO_DB_NAME', 'crmdb'),
        'USER': os.getenv('DJANGO_DB_USER', 'crmuser'),
        'PASSWORD': os.getenv('DJANGO_DB_PASSWORD', 'crmpassword'),
        'HOST': os.getenv('DJANGO_DB_HOST', 'db'),
        'PORT': os.getenv('DJANGO_DB_PORT', '5432'),
    }
}

# Archivos estáticos
STATIC_URL = '/static/'
STATIC_ROOT = os.path.join(BASE_DIR, 'staticfiles')
