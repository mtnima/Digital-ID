package com.smartmssa.digitalIDmiddleware.config;

import com.smartmssa.digitalIDmiddleware.dto.TokenDto;
import feign.Logger;
import feign.RequestInterceptor;
import feign.RequestTemplate;
import feign.Response;
import feign.codec.ErrorDecoder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.util.LinkedMultiValueMap;
import org.springframework.util.MultiValueMap;
import org.springframework.web.client.RestTemplate;


public class AnrptsClientConfig implements RequestInterceptor {

  private static final String AUTHORIZATION_HEADER="Authorization";
  private static final String TOKEN_TYPE = "Bearer";
  @Autowired
  private RestTemplate restTemplate;

  @Override
  public void apply(RequestTemplate requestTemplate) {
    requestTemplate.header(AUTHORIZATION_HEADER, String.format("%s %s", TOKEN_TYPE, getToken()));
  }

  @Bean
  public ErrorDecoder errorDecoder() {
    return new ErrorDecoder() {
      @Override
      public Exception decode(String s, Response response) {
        return new Exception("USER_NOT_FOUND");
      }
    };
  }

  private String getToken() {
    String url = "https://iam.eserviceslab.com:8443/realms/myrealm/protocol/openid-connect/token";
    MultiValueMap<String, String> authData = new LinkedMultiValueMap<>();
    authData.add("client_id", "general-client-fe");
    authData.add("username", "+22236224095");
    authData.add("password", "Az4N0*311Tiu");
    authData.add("grant_type", "password");
    HttpHeaders headers = new HttpHeaders();
    headers.setContentType(MediaType.APPLICATION_FORM_URLENCODED);
    HttpEntity<MultiValueMap<String, String>> requestToken = new HttpEntity<>(authData, headers);
    ResponseEntity<TokenDto> token = restTemplate.postForEntity(url, requestToken, TokenDto.class);
    return token.getBody().getAccess_token();
  }
}