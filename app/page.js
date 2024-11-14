// app/page.js
import Header from '@components/Header'; // Absolute import for Header component
// In app/page.js or wherever you're using the component
import TemperatureHumidityCards from '@components/TemperatureHumidityCards'; // Default import

export default function Home() {
  return (
    <div>
    <div>
      <Header />
    </div>
      <div>
        <TemperatureHumidityCards />
      </div>
      </div>
  );
}
