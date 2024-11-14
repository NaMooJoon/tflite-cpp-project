FROM notadevteam/hai-torizon-imx8mp:tf as builder

COPY . /app
WORKDIR /app/build

RUN cmake .. -DCMAKE_BUILD_TYPE=Release
RUN make -j$(nproc)

# ENTRYPOINT ["/app/build/tensorflow-app"]
