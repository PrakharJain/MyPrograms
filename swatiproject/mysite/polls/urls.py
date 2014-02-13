
from django.conf.urls import patterns, url

from polls import views

urlpatterns = patterns('',
    url(r'^q=(?P<poll_id>\w+)/$', views.index, name='index'),
    url(r'^$',views.start , name='Sample'),
)
