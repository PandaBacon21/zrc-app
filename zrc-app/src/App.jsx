import { Button, Container, Typography } from "@mui/material";
import { useState } from "react";

function App() {
  const [camaraState, setCameraState] = useState(false);

  const handleClick = async () => {
    try {
      if (camaraState) {
        setCameraState(false);
      } else {
        setCameraState(true);
      }
      console.log(camaraState);
    } catch (e) {
      console.log(e);
    }
  };

  return (
    <Container
      disableGutters
      maxWidth={false}
      sx={{
        width: "80%",
        minWidth: "300px",
        minHeight: "100vh",
        display: "flex",
        flexDirection: "column",
        justifyContent: "center",
        alignItems: "center",
        textAlign: "center",
        backgroundColor: "#303030",
        overflowX: "hidden",
      }}
    >
      <Typography variant="h2" sx={{ marginBottom: 10 }}>
        Zoom Rooms Controller App
      </Typography>
      <Typography variant="h4" sx={{ marginBottom: 5 }}>
        Zoom Room Name (replace later)
      </Typography>
      <Button variant="contained" onClick={handleClick}>
        Toggle Zoom Rooms Camera
      </Button>
    </Container>
  );
}

export default App;
