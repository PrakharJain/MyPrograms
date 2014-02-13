from django.conf.urls import patterns, include, url

from django.contrib import admin
from mysite import views


admin.autodiscover()



urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    url(r'^search/', include('polls.urls')),	
    url(r'^admin/', include(admin.site.urls)),
    url(r'^$',views.start , name='landingPage'),
    #url(r'^$', include('polls.urls'))

)
